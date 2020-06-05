// Package badgerdb provides the usage of init badger db
package badgerdb

import (
	"github.com/bigchange/go-pro/my_demo/utils"
	"github.com/dgraph-io/badger"
	"log"
)

var db *badger.DB

// InitBadgerDB init badger db instance
func InitBadgerDB(config *utils.LLBConfig) {
	// Open the Badger database located in the specific directory.
	// It will be created if it doesn't exist.
	opts := badger.DefaultOptions
	opts.Dir = config.BadgerDir
	opts.ValueDir = config.BadgerDir
	var err error
	// just open once before run db.Close()
	db, err = badger.Open(opts)
	if err != nil {
		log.Printf("open db error:", err.Error())
	}
}

// GetDB provide a way to get a initial db instance
func GetDB() *badger.DB {
	return db
}
