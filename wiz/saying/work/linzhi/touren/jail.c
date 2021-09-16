//jail.c 林芝村头人府的监狱秘道。
inherit VRM_SERVER;
void create()
{
        set_inherit_room( LIGHT_ROOM );
        set_maze_long(10);
        set_entry_dir("west");
        set_link_entry_dir("up");
        set_link_entry_room(__DIR__"secrety");
        set_link_exit_dir("east");
        set_link_exit_room(__DIR__"real_jail");
        set_entry_short("牢房");
        set_entry_desc(@LONG
这里是一间小小的牢房，墙壁上挂着点点水珠，非常的潮
湿，这里简直不是人住的地方，如果有谁被关在这里可真是倒
霉之极了。
LONG
);
        set_exit_short("地道");
        set_exit_desc(@LONG
这里是一间小小的牢房，墙壁上挂着点点水珠，非常的潮
湿，这里简直不是人住的地方，如果有谁被关在这里可真是倒
霉之极了。
LONG
);
        set_maze_room_short("地道");
        set_maze_room_desc(@LONG
这里是一间小小的牢房，墙壁上挂着点点水珠，非常的潮
湿，这里简直不是人住的地方，如果有谁被关在这里可真是倒
霉之极了。
LONG
);
        set_outdoors(0);
}
