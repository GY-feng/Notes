# 版本1,9/14/11:26

import threading

import numpy as np
from numpy.ma.core import indices

from PointCloudGridCutting.CloudPointGridCutting import CloudPointGridCutting
import open3d as o3d

output=[]
def count(cloud1,cloud2):
    kdtree = o3d.geometry.KDTreeFlann(cloud2)
    indices = []
    for i in range(len(cloud1.points)):
        [_, idx, _] = kdtree.search_radius_vector_3d(cloud1.points[0], radius)# 0号点在半径R内的所有点
        idx = np.asarray(idx, dtype=int)
        if len(idx) > 0:
            indices.append(i)

    cloud1.points = o3d.utility.Vector3dVector(np.array(cloud1.points)[indices])
    cloud1.colors = o3d.utility.Vector3dVector(np.array(cloud1.colors)[indices])
    output.append(cloud1)
    pass

def intersection(cloud_list : list[o3d.geometry.PointCloud], radius : float = 0.5):
    for cloud1 in cloud_list:
        for cloud2 in cloud_list:
            if cloud1==cloud2:
                continue
            threading_count=threading.Thread(target=count,kwargs={"cloud1":cloud1,"cloud2":cloud2})
            threading_count.start()

            

if __name__ == '__main__':
    cloud_list = []
    cloud_list.append(o3d.io.read_point_cloud("./data/129-scnu-40-40-10cm - Cloud.ply"))
    cloud_list.append(o3d.io.read_point_cloud("./data/130-scnu-40-40-10cm.ply"))

    tmp = intersection(cloud_list)
    o3d.visualization.draw_geometries(tmp, window_name='交集', width=800, height=600)

