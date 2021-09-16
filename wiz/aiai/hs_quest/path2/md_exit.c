// Room: /d/path2/dilao/md_exit.c

inherit ROOM;

int is_path2_dl() { return 1; }
protected int time, suolian = 1;
protected object *checks;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ��ܻ谵�ķ��䣬���ܵ�ʯͷǽ�ϻ����ż�����
������������ֻ��һ��ȭͷ��С��͸���ס�
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
                return notify_fail("��ɽ������������������⣬������ʦ���档\n");

        if(++time >= random(3)+3)
        {
                                
                message_vision("$N�������˼���ʯ�壬ʯ�塰��¡��һ�����Ϸ���¶����һ�����ڡ�\n",me);
                set("exits/up",me->query("quest/huashan_quest/my_place"));
        }
        else
                message_vision("$N�������˼���ʯ�壬ʯ����˿������\n",me);
        return 1;
}

int do_za(string arg)
{
        object zhan, weapon, me = this_player();

        if(!suolian)
                return 0;

        if(me->is_busy() || me->is_fighting())
                return notify_fail(BUSY_MESSAGE);

        if(arg != "����")
                return notify_fail("��Ҫ��ʲô��\n");

        if(objectp(zhan = present("zhan feixiong",this_object())))
        {
                message_vision("\n$N����$n������������ζ�˸����������ˣ���������\n",zhan,me);
                zhan->kill_ob(me);
                me->kill_ob(zhan);
                return notify_fail("");
        }

        if(!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("û��һ�����ֵļһ�����Ҳ���������\n");

        message_vision(sprintf("$N�Ӷ����е�%s��������ȥ��\nһ�°������ҿ��ˡ�\n",weapon->name()),me);

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
