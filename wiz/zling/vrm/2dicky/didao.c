// Room: /d/changan/didao.c

inherit VRM_SERVER;

void create()
{
        // 迷宫房间所继承的物件的档案名称。
set_inherit_room(ROOM);

        //迷宫的单边长
        set_maze_long(10);

        //入口方向(出口在对面)
        set_entry_dir("west");

        //入口与区域的连接方向
        set_link_entry_dir("west");

        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"tree1");

        //出口与区域的连接方向
        set_link_exit_dir("east");

        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"tree2");

        //入口房间短描述
        set_entry_short("松林");

        //入口房间描述
        set_entry_desc(@LONG
这里是一片茂盛的松林，林中静悄悄的，树林鸟语相间，遥相和呼，更为这寂
静的树林增添了几分神秘。向西望去,仿佛整片树林没有尽头
LONG
);

        //出口房间短描述
        set_exit_short("松林");

        //出口房间描述
        set_exit_desc(@LONG
这里是一片茂盛的松林，林中静悄悄的，树林鸟语相间，遥相和呼，更为这寂
静的树林增添了几分神秘。向东望去,仿佛整片树林没有尽头
LONG
);

        //迷宫房间的短描述
        set_maze_room_short("松林深处");

        //迷宫房间的描述，如果有多条描述，制造每个房
        //间的时候会从中随机选择一个。
        set_maze_room_desc(@LONG
这里是一片茂盛的松林，林中静悄悄的，树林鸟语相间，遥相和呼，更为这寂
静的树林增添了几分神秘。
LONG
);


        // 迷宫房间是否为户外房间？
        set_outdoors(1);
}
