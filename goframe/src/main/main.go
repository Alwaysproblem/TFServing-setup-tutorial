// Go offers built-in support for JSON encoding and
// decoding, including to and from built-in and custom
// data types.

package main

import (
    "encoding/json"
    "fmt"
    // "math"
    "errors"
    "os"
    "io/ioutil"
    // "reflect"
)

// Loadweights load item2vec weight 
func Loadweights(paths string) map[string]([]float64){

    // str := `{"spider-man": [ 1.433944821357727, 0.03582252189517021, 0.9901977181434631, -0.0008472169283777475, 1.0093321800231934],
    // "Dead_Pool": [ 1.4986339807510376, -0.04391840472817421, 0.9743974208831787, -0.030634721741080284, 1.0606716871261597]}`

    var dataStruct map[string]interface{}
    resultMap := make(map[string]([]float64))

    jsonFile, err := os.Open(paths)
    if err != nil{
        fmt.Println("there is something wrong with json files")
        panic(err)
    }

    byteValue, _ := ioutil.ReadAll(jsonFile)

    json.Unmarshal(byteValue, &dataStruct)
    // fmt.Println(dataStruct)

    for key, value := range dataStruct{
        vec := value.([]interface{})
        for _, val := range vec{
            if _, ok := resultMap[key]; ok{
                resultMap[key] = append(resultMap[key], val.(float64)) 
            }else{
                resultMap[key] = []float64{val.(float64), }
            }
        }
    }

    jsonFile.Close()
    return resultMap
}

// CosineDistance return score that use dot product. 
// weight a and weight b should be float number after normalization.
func CosineDistance(a []float64, b []float64) float64 {
    var dis float64 = 0

    if len(a) != len(b){
        panic(errors.New("the length should be same"))
    }

    for k := 0 ; k < len(a) ; k++ {
        dis += a[k] * b[k]
    }

    return dis
}

// ScoreItems scoring 2 different items.
func ScoreItems(ItemMap map[string]([]float64), ItemA string, ItemB string) (dis float64) {
    VecA, oka := ItemMap[ItemA]
    VecB, okb := ItemMap[ItemB]
    if oka == false || okb == false{
        panic(errors.New("the dictionary has no clue of these keys"))
    }
    
    dis = CosineDistance(VecA, VecB)
    return
}

func main() {
    resMap := Loadweights("../embedding_recaller/weights.json")
    // fmt.Println(reflect.TypeOf(resMap["Avengers"]))
    // fmt.Println(resMap["One_ring"])
    // var weighta = []float64{0.5816808938980103, 0.5637174248695374, -0.22879500687122345, 0.14512410759925842, -0.5200594663619995}
    // var weightb = []float64{0.5816808938980103, 0.5637174248695374, -0.22879500687122345, 0.14512410759925842, -0.5200594663619995}
    // var weightb = []float64{0.5729158520698547, 0.5918822884559631, -0.17938536405563354, 0.1752731204032898, -0.5084712505340576}
    // dis := CosineDistance(weighta, weightb)
    dis := ScoreItems(resMap, "One_ring", "Hobbits")
    fmt.Println("the distance is", dis)
}
