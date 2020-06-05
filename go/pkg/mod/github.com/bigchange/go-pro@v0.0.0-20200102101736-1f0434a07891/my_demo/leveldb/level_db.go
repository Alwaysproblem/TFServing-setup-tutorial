package leveldb

import (
	"errors"
	"fmt"
	"github.com/bigchange/go-pro/my_demo/utils"
	"github.com/syndtr/goleveldb/leveldb"
	"strconv"
	"testing"
)

func int64ToBytes(i int64) []byte {
	return []byte(string(strconv.FormatInt(i, 10)))
}

func bytesToInt64(b []byte) int64 {
	res, _ := strconv.ParseInt(string(b), 10, 64)
	return res
}

func TestBatchWrite() {
	db, err := leveldb.OpenFile("../data/leveldb", nil)
	if err != nil {
		fmt.Println("get data error", err.Error())
	}
	defer db.Close()
	batch := new(leveldb.Batch)
	var i int64
	for i = 0; i < 100; i++ {
		batch.Put(int64ToBytes(i), int64ToBytes(i+100))
	}
	batch.Delete(int64ToBytes(0))
	err = db.Write(batch, nil)
	if err != nil {
		utils.GetLogger().Infof("batch writer error:" + err.Error())
		return
	}

	value, err := Get(db, int64ToBytes(1))
	utils.GetLogger().Infof("Key: %v, value:%v", 1, string(value))
}

func Put(db *leveldb.DB, key []byte, value []byte) (err error) {
	err = db.Put(key, value, nil)
	return err
}

func Get(db *leveldb.DB, key []byte) (value []byte, err error) {
	value, err = db.Get(key, nil)
	if err != nil {
		return value, errors.New("DB Get ERROR")
	}
	return value, nil
}

func TestLevelDB(t *testing.T) {
	db, err := leveldb.OpenFile("../data/leveldb", nil)
	if err != nil {
		fmt.Println("get data error", err.Error())
	}
	// Remember that the contents of the returned slice should not be modified.
	data, err := db.Get([]byte("key"), nil)
	if err == nil {
		fmt.Println("get data:", string(data))
	} else {
		fmt.Println("get data error:", err.Error())
	}
	err = db.Put([]byte("key"), []byte("value"), nil)
	data, err = db.Get([]byte("key"), nil)
	if err == nil {
		fmt.Println("get data:", string(data))
	} else {
		fmt.Println("get data error", err.Error())
	}
	err = db.Delete([]byte("key"), nil)
	fmt.Println("get data:", string(data))

	defer db.Close()
}
