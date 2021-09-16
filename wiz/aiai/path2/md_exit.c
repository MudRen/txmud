// Room: /d/path2/dilao/md_exit.c

inherit ROOM;

int is_path2_dl() { return 1; }
protected int time, suolian = 1;
protected object *checks;

void create()
{
        set("short", "暗堂");
        set("long", @LONG
这里是一间很昏暗的房间，四周的石头墙上还钉着几条铁
锁链，铁门上只有一个拳头大小的透气孔。
LONG
        );

        set("no_clean_up", 1);
        //setup();
        if(clonep())
                call_out("free_all_rooms",900);
}

void init()
{
        add_action("do_push","push");
        add_action("do_za","za");
}

int do_push(string arg)
{
        object me = this_player();

        if(query("exits/up"))
                return 0;

        if(me->is_busy() || me->is_fighting())
                return notify_fail(BUSY_MESSAGE);

        if (!me->query("quest/huashan_quest/my_place"))
        {
                me->set("quest/huashan_quest/my_place", "/d/tianshui/caizhu3");
                //return notify_fail("华山“飞贼”任务出现问题，请向巫师报告。\n");
        }

        if(++time >= random(3)+3)
        {
                                
                message_vision("$N用力推了几下石板，石板“轰隆”一声向上翻起，露出了一个出口。\n",me);
                set("exits/up",me->query("quest/huashan_quest/my_place"));
        }
        else
                message_vision("$N用力推了几下石板，石板纹丝不动。\n",me);
        return 1;
}

int do_za(string arg)
{
        object zhan, weapon, me = this_player();

        if(!suolian)
                return 0;

        if(me->is_busy() || me->is_fighting())
                return notify_fail(BUSY_MESSAGE);

        if(arg != "锁链")
                return notify_fail("你要砸什么？\n");

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

int valid_leave(object who,string dir)
{
        if(dir == "up")
                call_out("free_all_rooms",2);
        who->delete("quest/huashan_quest/my_place");
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
