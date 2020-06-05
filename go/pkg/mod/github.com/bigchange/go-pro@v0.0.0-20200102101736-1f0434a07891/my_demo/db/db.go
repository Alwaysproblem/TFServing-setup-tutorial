/*
 * @Author: Jerry You
 * @CreatedDate: 2018-05-25 16:44:56
 * @Last Modified by: Jerry You
 * @Last Modified time: 2018-05-25 16:45:25
 */
package db

import (
	"database/sql"
	"fmt"
	"log"
	"os"

	"github.com/bigchange/go-pro/my_demo/utils"
	"github.com/go-gorp/gorp"
	_ "github.com/go-sql-driver/mysql" //import postgres
)

//DB ...
type DB struct {
	*sql.DB
}

const (
	//DbUser ...
	DbUser = ""
	//DbPassword ...
	DbPassword = ""
	//DbName ...
	DbName = ""

	DbHost = ""
)

var db *gorp.DbMap

// Init ...
func Init() {

	// dbinfo := fmt.Sprintf("tcp:%s:3306*%s/%s/%s",
	// DbHost, DbName, DbUser, DbPassword)

	dbinfo := fmt.Sprintf("%s:%s@tcp(%s:3306)/%s",
		DbUser, DbPassword, DbHost, DbName)

	var err error
	db, err = ConnectDB(dbinfo)
	if err != nil {
		utils.GetLogger().Fatal(err)
	}

}

//Init ...
func InitDB(config *utils.LLBConfig) {

	// dbInfo := fmt.Sprintf("user=%s password=%s host=%s port=5432 dbname=%s sslmode=disable", config.DbUser, config.DbPass, config.DbHost, config.DbName)
	dbInfo := fmt.Sprintf("%s:%s@tcp(%s:3306)/%s",
		config.DbUser, config.DbPass, config.DbHost, config.DbName)

	// user:password@tcp(localhost:5555)/dbname
	var err error
	db, err = ConnectDB(dbInfo)
	if err != nil {
		utils.GetLogger().Fatal(err)
	}

}

// ConnectDB ...
func ConnectDB(dataSourceName string) (*gorp.DbMap, error) {
	utils.GetLogger().Infof("connect to :%v ", dataSourceName)
	db, err := sql.Open("mysql", dataSourceName)
	if err != nil {
		return nil, err
	}
	if err = db.Ping(); err != nil {
		return nil, err
	}
	dbmap := &gorp.DbMap{Db: db, Dialect: gorp.MySQLDialect{"InnoDB", "UTF8"}}
	dbmap.TraceOn("[gorp]", log.New(os.Stdout, "go-pro:", log.Lmicroseconds)) //Trace database
	// requests
	return dbmap, nil
}

// GetDB ...
func GetDB() *gorp.DbMap {
	return db
}
