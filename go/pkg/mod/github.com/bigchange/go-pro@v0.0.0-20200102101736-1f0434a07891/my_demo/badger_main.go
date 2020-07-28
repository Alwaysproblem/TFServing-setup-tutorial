package main

import (
	"encoding/binary"
	"github.com/bigchange/go-pro/my_demo/badgerdb"
	"github.com/bigchange/go-pro/my_demo/utils"
	"github.com/dgraph-io/badger"
	"log"
	"time"
)

func init() {
	config := &utils.LLBConfig{
		BadgerDir: "../data/db"}
	badgerdb.InitBadgerDB(config)
}

func checkError(msg string, err error) {
	if err != nil {
		log.Println(msg, err.Error())
	}
}
func uint64ToBytes(i uint64) []byte {
	var buf [8]byte
	binary.BigEndian.PutUint64(buf[:], i)
	return buf[:]
}

func bytesToUint64(b []byte) uint64 {
	return binary.BigEndian.Uint64(b)
}

// Merge function to add two uint64 numbers
func mergerAdd(existing, new []byte) []byte {
	return uint64ToBytes(bytesToUint64(existing) + bytesToUint64(new))
}
func MergeOperator(key string) {
	m := badgerdb.GetDB().GetMergeOperator([]byte(key), mergerAdd, 200*time.Millisecond)
	defer m.Stop()
	m.Add(uint64ToBytes(1))
	m.Add(uint64ToBytes(2))
	m.Add(uint64ToBytes(3))
	res, err := m.Get() // res should have value 6 encoded
	if err != nil {
		log.Println("MergeOperator error:", err.Error())
	}
	log.Println("Merge:", bytesToUint64(res))
}

func main() {
	// test manage txn by self
	key := "merge"
	db := badgerdb.GetDB()
	defer db.Close()
	err := db.Update(func(txn *badger.Txn) error {
		err := txn.Set([]byte(key), uint64ToBytes(0))
		if err != nil {
			return err
		}
		return nil
	})
	checkError("merge set", err)
	MergeOperator(key)

}
