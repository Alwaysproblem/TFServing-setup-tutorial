import json
import os
import glob

datasetdir = "Dataset"
basicPath = os.path.split(os.path.split(__file__)[0])[0]

class Data(object):
    def __init__(self, **kwargs):
        pass

class TrainData(Data):
    def __init__(self, readMode = 'r', basicPath = basicPath, **kwargs):
        super(TrainData, self).__init__(**kwargs)
        self.readMode = readMode
        self.datasetpath = os.path.join(basicPath, datasetdir)

    def DecodeFromJson(self, jsonFileName, basicPath = basicPath):
        """
            import the train data from json that includes all train files name.
            
            return: the tensorflow record object.
        """
        filePath = os.path.join(basicPath, datasetdir, jsonFileName)
        with open(filePath) as f:
            filedict = json.load(f)
            if "train_files_paths" not in filedict or "test_files_paths" not in filedict:
                raise KeyError("there is no such key, please check the json file.")
        
        return filedict["train_files_paths"], filedict["test_files_paths"]

    def _readfromFiles(self, *paths: list):
        """
            assuming that there are more than one files in the dataset folder.
            we can read the data from those files.

            return: tensorflow dataset object.
        """
        for p in paths:
            self.readfromFile(p)

        #TODO complete the whole programe and finish the IO function.
        return None

    def _readfromFile(self, path: str):
        """
            assuming that there is just one files in the dataset folder.
            we can read the data from the file.

            return: tensorflow dataset object.
        """
        if path.split('.')[-1] == 'csv':
            #TODO for the csv file 
            pass
        else:
            pass


class TrainDataGenerator(TrainData):
    def __init__(self, readMode = 'r', basicPath = basicPath):
        super(TrainDataGenerator, self).__init__(readMode, basicPath)

    def __next__(self):
        pass

    def __call__(self):
        return next(self)

if __name__ == "__main__":
    # with open(os.path.join(basicPath, 'Dataset', 'aa.json')) as f:
    #     print(f.readlines())
    a = TrainData().from_a_json(jsonFileName="aa.json")
    print(a)