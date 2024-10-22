from collections.abc import MutableMapping
class MapBase(MutableMapping):
    """映射的基本类，定义基本接口"""

    def __init__(self):
        super().__init__()

    def __getitem__(self, key):
        raise NotImplementedError("Must be implemented by subclass.")

    def __setitem__(self, key, value):
        raise NotImplementedError("Must be implemented by subclass.")

    def __delitem__(self, key):
        raise NotImplementedError("Must be implemented by subclass.")

    def __iter__(self):
        raise NotImplementedError("Must be implemented by subclass.")

    def __len__(self):
        raise NotImplementedError("Must be implemented by subclass.")
class SortedTableMap(MapBase):
    def _findindex
    pass
