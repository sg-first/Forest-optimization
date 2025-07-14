Forest optimization
=======
基于HISM的三万颗树，动态创建instance（不烘培光照）

树模型
-------
![tree1](img/tree1.png)
![tree2](img/tree2.png)

做的LOD1，高空时枝叶效果与LOD0类似，屏占比0.03时切换

### LOD效果
![LOD1](img/LOD1.png)
![LOD2](img/LOD2.png)

参数调整
---------
光源shadow cascade bias distribution设为0，让低级别阴影贴图的物体屏占比更小，使切换更平滑

效果
---------

### I7 10700 + 3060
FPS平均120左右

![3060](img/3060-1.jpg)
![3060](img/3060-2.jpg)
![3060](img/3060-3.jpg)

### I7 7700HQ + 1050ti
FPS平均50左右

![1050](img/1050-1.jpg)
![1050](img/1050-2.jpg)
![1050](img/1050-3.jpg)

Profile
-----------

## sceneRendering
最终场景

![stat](img/stat-sr.png)

仅树

![stat](img/stat-sr-raw.png)

说明地形drawcall 400左右

## engine
最终场景

![stat](img/stat-e.png)

仅树

![stat](img/stat-e-raw.png)

## session
![session](img/session1.png)

![session](img/session2.png)

3060 4K全屏能提升5帧左右