# TAG功能介绍

## 静态属性查询

### OHOS\_ABILITY\_CAMERA\_POSITION
查询相机的位置信息，例如前置、后置等，位置信息定义如下：

| OHOS\_ABILITY\_CAMERA\_POSITION      | 用于查询相机的位置信息 |
| ------------------------------------ | ------------------ |
| OHOS\_CAMERA\_POSITION\_FRONT        | 前置               |
| OHOS\_CAMERA\_POSITION\_BACK         | 后置               |
| OHOS\_CAMERA\_POSITION\_OTHER        | 其他               |


### OHOS\_ABILITY\_CAMERA_TYPE
查询相机的功能类型，例如广角、长焦等，类型定义如下：

| OHOS\_ABILITY\_CAMERA\_TYPE      | 用于查询相机的功能类型 |
| ---------------------------------| ------------------ |
| OHOS\_CAMERA\_TYPE\_WIDE\_ANGLE  | 广角镜头            |
| OHOS\_CAMERA\_TYPE\_ULTRA\_WIDE  | 超广角镜头          |
| OHOS\_CAMERA\_TYPE\_TELTPHOTO    | 长焦镜头            |
| OHOS\_CAMERA\_TYPE\_TRUE\_DEAPTH | 景深镜头            |
| OHOS\_CAMERA\_TYPE\_LOGICAL      | 逻辑镜头            |
| OHOS\_CAMERA\_TYPE\_UNSPECIFIED  | 未定义镜头          |


### OHOS\_ABILITY\_CAMERA\_CONNECTION\_TYPE
查询相机的链接类型，例如板载、USB外接、远程等，类型定义如下：

| OHOS\_ABILITY\_CAMERA\_CONNECTION\_TYPE         | 查询相机设备的连接类型 |
|-------------------------------------------------| ------------------ |
| OHOS\_CAMERA\_CONNECTION\_TYPE\_BUILTIN         | 板载相机            |
| OHOS\_CAMERA\_CONNECTION\_TYPE\_USB\_PLUGIN     | USB外接相机         |
| OHOS\_CAMERA\_CONNECTION\_TYPE\_REMOTE          | 远程相机            |


### OHOS\_ABILITY\_FOCAL\_LENGTH
查询相机的镜头焦距，浮点型数值。


### OHOS\_SENSOR\_ORIENTATION

32位整型数值，表示镜头的安装角度，通常指镜头想对于设备正常握持方向的偏转角度。


## 分辨率及图像格式控制
### OHOS\_ABILITY\_STREAM\_AVAILABLE\_BASIC\_CONFIGURATIONS
用于查询支持的分辨率及图像格式，32位整型数组，格式如下：

[图像格式1, 分辨率宽， 分辨率高， 图像格式2, 分辨率宽， 分辨率高， ......]

格式举例：

[1, 640, 480, 4, 1280, 960]

图像格式信息定义如下：

| OHOS\_ABILITY\_STREAM\_AVAILABLE\_BASIC\_CONFIGURATIONS | 查询支持的分辨率及图像格式 |
| ------------------------------------------------------- | --------------------- |
| OHOS\_CAMERA\_FORMAT\_RGBA\_8888 = 1                    | RGBA8888              |
| OHOS\_CAMERA\_FORMAT\_YCBCR\_420\_888 = 2               | YCBCR420_888          |
| OHOS\_CAMERA\_FORMAT\_YCRCB\_420\_SP = 3                | YCRCB420_SP           |
| OHOS\_CAMERA\_FORMAT\_JPEG = 4                          | JPEG                  |

### OHOS\_CONTROL\_FPS\_RANGES
32位整型数组，用于下发帧率范围。


## 基于模式的基础规格及特性能力查询
### OHOS\_ABILITY\_STREAM\_AVAILABLE\_EXTEND\_CONFIGURATIONS
按照模式场景及流类型查询基础规格及特性能力，32位整型数组，格式如下：

[模式1, 流类型1, 能力信息1, 能力信息2, ..., 结束符, 流类型2, 能力信息1, 能力信息2, ..., 结束符，结束符号，模式2, 流类型1, 能力信息1, 能力信息2, ..., 结束符, 流类型2, 能力信息1, 能力信息2, ..., 结束符，结束符]

结束符约定为-1，其中能力信息格式为：

[图像格式，分辨率宽， 分辨率高， 固定帧率， 动态帧率下限， 动态帧率上限， 特性能力1, 特性能力2, ...， 结束符]

其中特性能力采用其对应查询TAG表示。

格式举例：

[0, 0, 1, 640, 480, 0, 0, 0, -1, 1, 1, 640, 480, 30, 30, 30, -1, 2, 4, 1280, 960, 0, 0, 0, -1, -1, 1, 0, 1, 640, 480, 0, 0, 0, 虚化, 滤镜, 美颜, -1, 1, 2, 4, 1280, 960, 0, 0, 0, 虚化, -1, -1]

PS: '虚化'为OHOS_ABILITY_SCENE_PORTRAIT_EFFECT_TYPES, '滤镜'为OHOS_ABILITY_SCENE_FILTER_TYPES, '美颜'为OHOS_ABILITY_SCENE_BEAUTY_TYPES。


## 拍照镜像控制

### OHOS\_CONTROL\_CAPTURE\_MIRROR\_SUPPORTED
8位整型，用于查询是否支持拍照镜像，0表示不支持，1表示支持。

### OHOS\_CONTROL\_CAPTURE\_MIRROR
8位整型，用于下发控制拍照镜像，1表示开启镜像，0表示关闭。


## 缩放控制
 
### OHOS\_ABILITY\_ZOOM\_RATIO\_RANGE
用于查询支持的缩放比例范围，浮点型数值区间，格式如下：

[ZOOM下限，ZOOM上限]

举例：

[1.000000, 6.000000] -- 缩放比例范围为1.0到1.0倍。

### OHOS\_ABILITY\_SCENE\_ZOOM\_CAP
用于查询不同模式下的缩放比例范围，32位整型数组，格式如下:

[模式1， ZOOM下限， ZOOM上限， 模式2， ZOOM下限，ZOOM上限，...]

举例：

[0, 1, 5, 1, 1, 3] -- NORMAL模式下缩放比例为1～5倍， 人像模式下为1～3倍。

### OHOS\_CONTROL\_ZOOM\_RATIO
整型数值， 用于下发缩放比例。


## 对焦控制
### OHOS\_ABILITY\_FOCUS_MODES
用于查询支持对焦模式，8位整型数组，格式如下：

[对焦模式1, 对焦模式2, ......]

举例：

[1, 2] -- 支持连续自动对焦和自动对焦

对焦模式类型定义如下：

| OHOS\_ABILITY\_FOCUS_MODES                 | 数值 | 用于查询支持的对焦模式 |
| ------------------------------------------ | ---- | ---------------------- |
| OHOS\_CAMERA\_FOCUS\_MODE\_MANUAL          | 0    | 手动                   |
| OHOS\_CAMERA\_FOCUS\_MODE\_CONTINUOUS_AUTO | 1    | 连续自动               |
| OHOS\_CAMERA\_FOCUS\_MODE\_AUTO            | 2    | 自动                   |
| OHOS\_CAMERA\_FOCUS\_MODE\_LOCKED          | 3    | 锁定                   |

### OHOS\_CONTROL\_FOCUS\_MODE
8位整型，用于下发对焦模式。


## 曝光控制
### OHOS\_ABILITY\_EXPOSURE\_MODES
8位整型数组，查询支持的曝光模式，类型定义如下：

| OHOS\_ABILITY\_EXPOSURE\_MODES                | 用于查询支持的曝光模式 |
| --------------------------------------------- | ---------------------- |
| OHOS\_CAMERA\_EXPOSURE\_MODE\_MANUAL          | 手动                   |
| OHOS\_CAMERA\_EXPOSURE\_MODE\_CONTINUOUS_AUTO | 连续自动               |
| OHOS\_CAMERA\_EXPOSURE\_MODE\_AUTO            | 自动                   |
| OHOS\_CAMERA\_EXPOSURE\_MODE\_LOCKED          | 锁定                   |

### OHOS\_CONTROL\_EXPOSURE\_MODE
8位整型，用于下发曝光模式。


## 曝光补偿控制
### OHOS\_CONTROL\_AE\_COMPENSATION\_RANGE
用于查询自动曝光补偿范围，32位整型区间，格式如下：

[范围下限, 范围上限]

格式举例：

[-4, 4]

### OHOS\_CONTROL\_AE\_COMPENSATION\_STEP
用于查询自动曝光补偿步长，rational类型，格式如下：

```
typedef struct camera_rational {
    int32_t numerator;
    int32_t denominator; 
} camera_rational_t;
```

格式举例：

[1, 2] -- 表示步长为1/2。

### OHOS\_CONTROL\_AE\_EXPOSURE\_COMPENSATION
32位整型，用于下发曝光补偿值。


## 人类检测控制
### OHOS\_STATISTICS\_FACE\_DETECT\_MODE
8位整型数值，用于查询是否支持人脸检测，取值0表示不支持，取值1表示支持。

### OHOS\_STATISTICS\_FACE\_DETECT\_SWITCH
8位整型，用于下发人脸检测开关，1表示开启，0表示关闭。


## 静音控制
### OHOS\_ABILITY\_MUTE\_MODES
8位整型数组，用于查询支持的静音模式，类型定义如下：

| OHOS\_ABILITY\_MUTE\_MODES                       | 用于查询支持的静音模式 |
| ------------------------------------------------ | ------------------ |
| OHOS\_CAMERA\_MUTE\_MODE\_OFF                    | 关闭或不支持         | 
| OHOS\_CAMERA\_MUTE\_MODE\_SOLID\_COLOR\_BLACK    | 黑色                |

### OHOS\_CONTROL\_MUTE\_MODE
8位整型，用于下发静音模式。


## 录像防抖控制
### OHOS\_ABILITY\_VIDEO\_STABILIZATION\_MODES
8位整型数组，查询支持的视频防抖模式，类型定义如下：

| OHOS\_ABILITY\_VIDEO\_STABILIZATION\_MODES     | 查询支持的视频防抖模式 |
| ---------------------------------------------- | ------------------ |
| OHOS\_CAMERA\_VIDEO\_STABILIZATION\_OFF        | 关闭或不支持         | 
| OHOS\_CAMERA\_VIDEO\_STABILIZATION\_LOW,       | 低                |
| OHOS\_CAMERA\_VIDEO\_STABILIZATION\_MIDDLE,    | 中                |
| OHOS\_CAMERA\_VIDEO\_STABILIZATION\_HIGH,      | 高                |
| OHOS\_CAMERA\_VIDEO\_STABILIZATION\_AUTO,      | 自动              |

### OHOS\_CONTROL\_VIDEO\_STABILIZATION\_MODE
8位整型，用于下发防抖模式。


## 闪光灯打闪模式控制
### OHOS\_ABILITY\_FLASH_\_MODES
查询支持的闪光灯模式，8位整型数组，类型定义如下：

| OHOS\_ABILITY\_FLASH\_MODES                |  用于查询支持的闪光灯模式 |
| ------------------------------------------ | ------------------- |
| OHOS\_CAMERA\_FLASH\_MODE\_CLOSE           | 关闭或不支持    |
| OHOS\_CAMERA\_FLASH\_MODE\_OPEN            | 打开           |
| OHOS\_CAMERA\_FLASH\_MODE\_AUTO            | 自动           |
| OHOS\_CAMERA\_FLASH\_MODE\_ALWAYS_OPEN     | 始终开启        |

### OHOS\_CONTROL\_FLASH_\_MODE
8位整型，用于下发打闪模式。


## 帧率控制
### OHOS\_ABILITY\_FPS\_RANGES
32位整型数组，用于查询支持的帧率范围。

### OHOS\_CONTROL\_FPS\_RANGES
32位整型数组，用于下发帧率范围。

## 状态反馈
### OHOS\_CONTROL\_EXPOSURE\_STATE
8位整型数值，查询当前曝光状态，定义如下：

| OHOS\_CONTROL\_EXPOSURE\_STATE | 查询当前曝光状态 |
| ------------------------------ | -------------- |
|OHOS\_CAMERA\_EXPOSURE\_STATE\_SCAN|扫描中|
|OHOS\_CAMERA\_EXPOSURE\_STATE\_CONVERGED|已汇聚|


### OHOS\_CONTROL\_FOCUS\_STATE
8位整型数值，查询当前对焦状态，定义如下：

| OHOS\_CONTROL\_FOCUS\_STATE | 查询当前对焦状态 |
| ---------------------------| ----------------- |
|OHOS\_CAMERA\_FOCUS\_STATE\_SCAN | 扫描中 |
|OHOS\_CAMERA\_FOCUS\_STATE\_FOCUSED | 已完成对焦 |
|OHOS\_CAMERA\_FOCUS\_STATE\_UNFOCUSED | 未完成对焦 |

### OHOS\_CONTROL\_FLASH\_STATE
8位整型数值，查询当前闪光灯状态，定义如下：

| OHOS\_CONTROL\_FLASH\_STATE | 查询当前闪光灯状态 |
| ---------------------------| ----------------- |
|OHOS\_CAMERA\_FLASH\_STATE\_UNAVAILABLE | 不可用 |
|OHOS\_CAMERA\_FLASH\_STATE\_CHARGING | 充电中 |
|OHOS\_CAMERA\_FLASH\_STATE\_READY | 就绪 |
|OHOS\_CAMERA\_FLASH\_STATE\_FLASHING | 打闪中 |
|OHOS\_CAMERA\_FLASH\_STATE\_UNKNOWN | 未知 |

# TAG下发控制约定
## 增量控制约定
上层给HDI下发TAG参数时，仅需下发需要变更的参数，未下发的参数默认保持不变。

## 特殊行为约定
部分TAG在下发控制上存在其特有行为，汇总如下：

| TAG名称 | 说明 | 控制逻辑|
| ----------------------------- | ------| ------ |
| OHOS\_JPEG\_GPS\_COORDINATES  | 设置JPEG图片的地理位置信息 | 只针对下发后的第一次拍照生效，每次拍照前需独立下发，不下发默认没有地理位置|


