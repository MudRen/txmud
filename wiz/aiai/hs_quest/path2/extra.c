// Room: /d/path2/dilao/extra.c

#include <room.h>

inherit ROOM;

int is_path2_dl() { return 1; }
protected int time, suolian = 1;
protected object *checks;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是一间阴暗潮湿的密室，四周的石头墙上还钉着几条铁
锁链。
LONG
        );

        set("no_clean_up", 1);
        //setup();
        //create_door("westup", "铁门", "eastdown", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/key");
        if(clonep())
                call_out("free_all_rooms",900);
}

void init()
{
        add_action("do_za","za");
        add_action("do_push","push");
}

int do_za(string arg)
{
        object zhan, weapon, me = this_player();
        object npc;
        int exp;

        if(!suolian)
                return 0;

        if(me->is_busy() || me->is_fighting())
                return notify_fail(BUSY_MESSAGE);

        if(arg != "锁链")
                return notify_fail("你要砸什么？\n");

        if(random(3) && !me->query("quest/huashan_quest/killed_zfx"))   // zfx回老巢
        {
                npc = new(__DIR__"npc/zhan");
                exp = me->query("combat_exp");
                if(exp > npc->query("combat_exp"))
                        npc->set("combat_exp",exp);
                npc->move(environment(me));
                for (exp=0; exp<random(5); exp++)
                {
                        npc = new(__DIR__"npc/loulou");
                        npc->move(environment(me));
                }
                if (exp)
                        message_vision("\n$N正想砸锁链，展飞雄刚好带手下回来了。\n",me);
                else

                        message_vision("\n$N正想砸锁链，展飞雄突然回来了。\n",me);
        }

        if(objectp(zhan = present("zhan feixiong",this_object())))
        {
                message_vision("\n$N朝着$n喊道：“活腻味了敢跑这来劫人！找死！”\n",zhan,me);
                zhan->kill_ob(me);
                me->kill_ob(zhan);
                return notify_fail("");
        }

        if(!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("没有一件乘手的家伙，恐怕砸不开锁链。\n");

        message_vision(sprintf("$N挥动手中的%s向锁链砸去。\n一下把锁链砸开了。\n",weapon->name()),me);

        suolian = 0;
        set("long", @LONG
这里是一间阴暗潮湿的牢房，四周的石头墙上的铁锁链被砸
坏了。
LONG
        );

        call_out("free_girl",1,me);
        return 1;
}

protected void free_girl(object me)
{
        object girl;

        if(!me || (environment(me) != this_object()))
                return;

        if(!objectp(girl = present("xiu xiu",this_object())))
                return;

        girl->been_free(me);
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

