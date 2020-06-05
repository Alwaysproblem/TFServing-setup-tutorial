package rocksdb

import (
	"github.com/bigchange/go-pro/my_demo/utils"
	"github.com/tecbot/gorocksdb"
)

var db *gorocksdb.DB

func init() {
	bbto := gorocksdb.NewDefaultBlockBasedTableOptions()
	bbto.SetBlockCache(gorocksdb.NewLRUCache(3 << 30))
	opts := gorocksdb.NewDefaultOptions()
	opts.SetBlockBasedTableFactory(bbto)
	opts.SetCreateIfMissing(true)
	db, err := gorocksdb.OpenDb(opts, "../data/rocksdb")
}

func TestRocksDB() {
	ro := gorocksdb.NewDefaultReadOptions()
	wo := gorocksdb.NewDefaultWriteOptions()
	// if ro and wo are not used again, be sure to Close them.
	err = db.Put(wo, []byte("foo"), []byte("bar"))
	value, err := db.Get(ro, []byte("foo"))
	defer value.Free()
	if err != nil {
		utils.GetLogger().Infof("Get data error: %v", err.Error())
		return
	}
	utils.GetLogger().Infof("Get data: %v", value.Data())
	err = db.Delete(wo, []byte("foo"))
}
