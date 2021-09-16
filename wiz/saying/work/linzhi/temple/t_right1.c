//t_right1.c 德木寺内的塔林。
inherit VRM_SERVER;
void create()
{
        set_inherit_room(ROOM);
        set_maze_long(10);
        set_entry_dir("west");
        set_link_entry_dir("west");
        set_link_entry_room(__DIR__"temple1");
        set_link_exit_dir("east");
        set_link_exit_room(__DIR__"fire_hole");
        set_entry_short("塔林");
        set_entry_desc(@LONG
这里是德木寺的塔林，密密麻麻的全都是前辈僧人的遗骨
存放之塔，似乎有点阴气森森地。
LONG
);
        set_exit_short("塔林");
        set_exit_desc(@LONG
这里是德木寺的塔林，密密麻麻的全都是前辈僧人的遗骨
存放之塔，似乎有点阴气森森地。
LONG
);
        set_maze_room_short("塔林");
        set_maze_room_desc(@LONG
这里是德木寺的塔林，密密麻麻的全都是前辈僧人的遗骨
存放之塔，似乎有点阴气森森地。
LONG
);
        set_outdoors(1);
}
