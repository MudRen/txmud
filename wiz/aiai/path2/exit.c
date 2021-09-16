// Room: /d/path2/dilao/exit.c

#include <room.h>

inherit ROOM;

int is_path2_dl() { return 1; }
protected int time, suolian = 1;
protected object *checks;

void create()
{
        set("short", "�η�");
        set("long", @LONG
������һ��������ʪ���η����η�������һ�顺ʯ�塻������
���ر�
LONG
        );

        set("no_clean_up", 1);
        //setup();
                //create_door("eastdown", "����", "westup", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/key");
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
                message_vision("$N�������˼���ʯ�壬ʯ�塰��¡��һ�����Ϸ���¶����һ�����ڡ�\n",me);
                set("exits/up",__DIR__"clu1");
        }
        else
                message_vision("$N�������˼���ʯ�壬ʯ����˿������\n",me);
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
                        return notify_fail("��û�����ŵ�Կ�ס�\n");
                if ( !key->query("for_xiuxiu") )
                        return notify_fail("����Կ��ͱ�˰��죬����ȴ�򲻿����š�\n");
                write("����Կ�״������š�\n");
                who->delete_temp("hs_quest_jail_enter");
                destruct(key);
                return 1;
        }
        else
        {
                return notify_fail("����˰��쾢�������Ż��ǽ����š�\n");
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
