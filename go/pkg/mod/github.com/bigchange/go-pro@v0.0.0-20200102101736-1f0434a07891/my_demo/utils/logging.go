package utils

import (
	"github.com/op/go-logging"
	// logrus "github.com/sirupsen/logrus"
	// seelog "github.com/cihub/seelog"
)

var logger *logging.Logger

func init() {
	logger = logging.MustGetLogger("case-go")
}

func Init() error {
	logger = logging.MustGetLogger("case-go")
	return nil
}

func GetLogger() *logging.Logger {
	return logger
}
