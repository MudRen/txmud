// Room: /d/path2/dilao/exit.c

#include <room.h>

inherit ROOM;

int is_path2_dl() { return 1; }
protected int time, suolian = 1;
protected object *checks;

void create()
{
        set("short", "牢房");
        set("long", @LONG
这里是一间阴暗潮湿的牢房，牢房顶上有一块『石板』看起来
很特别。
LONG
        );

        set("no_clean_up", 1);
        //setup();
                //create_door("eastdown", "铁门", "westup", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/key");
        if(clonep())
                call_out("free_all_rooms",900);
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me = this_player();

        if(query("exits/up"))
                return 0;

        if(me->is_busy() || me->is_fighting())
                return notify_fail(BUSY_MESSAGE);

        if(++time >= 3)
        {
                message_vision("$N用力推了几下石板，石板“轰隆”一声向上翻起，露出了一个出口。\n",me);
                set("exits/up",__DIR__"clu1");
        }
        else
                message_vision("$N用力推了几下石板，石板纹丝不动。\n",me);
        return 1;
}

int valid_leave(object who,string dir)
{
        object key;

        if(dir == "up")
        {
                call_out("free_all_rooms",2);
        }
        else if (dir == "eastdown" &&
                who->query_temp("hs_quest_jail_enter"))
        {
		if ( !objectp(key=present("small key", who)) )
                        return notify_fail("你没有牢门的钥匙。\n");
                if ( !key->query("for_xiuxiu") )
                        return notify_fail("你用钥匙捅了半天，但是却打不开牢门。\n");
                write("你用钥匙打开了牢门。\n");
                who->delete_temp("hs_quest_jail_enter");
                destruct(key);
                return 1;
        }
        else
        {
                return notify_fail("你费了半天劲，但牢门还是紧闭着。\n");
        }
        return 1;
}

void set_check_array(object *tmp)
{
        if(!arrayp(tmp) || !sizeof(tmp))
                return;
        checks = tmp;
}

protected void free_all_rooms()
{
        if(!arrayp(checks) || !sizeof(checks))
        {
                if(clonep())
                        destruct(this_object());
                return;
        }

        if(sizeof(filter_array(all_inventory(this_object()),(: userp :))))
        {
                call_out("free_all_rooms",5);
                return;
        }

        foreach(object ob in checks)
        {
                if(!ob)
                        continue;
                if(sizeof(filter_array(all_inventory(ob),(: userp :))))
                {
                        call_out("free_all_rooms",5);
                        return;
                }
        }

        foreach(object ob in checks)
        {
                if(!ob)
                        continue;
                destruct(ob);
        }

        destruct(this_object());
}
