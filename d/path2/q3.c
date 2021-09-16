// Room: /d/path2/q3.c

inherit ROOM;

void create()
{
        set("short", "ʯ����");
        set("long", @LONG
����һ��ʯͷ��ķ��ӣ����ڳ�ʱ��û�˾�ס�������Ѿ�
�������Ӳݣ������Ｘ���򵥵ļҾ��Ѿ��ưܲ�����ǽ�ϲ��ٵ�
��������̦�������ǽ��ȴ��һ�顸ʯ�项�ǳ��⻬��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"q2",
]));

        set("item_desc",([
        "ʯ��" : "���ʯͷ����ǳ��⻬�����񾭳����˰���\n",
]));

        setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object ob,enter,xin,me = this_player();

        if(arg != "ʯ��")
                return notify_fail("��Ҫ��ʲô��\n");

        if( (arg != "ʯ��")
        || (me->query("class") != "huashan")
        || (me->query("quest/huashan_quest/name") != "����չ���ܵ��ټ�")
        || !me->query("quest/huashan_quest/asked_zhang")
        || me->query("quest/huashan_quest/entered") )
                return notify_fail("���������˼���ʯ�飬����ʲô��ӦҲû�С�\n");

        ob = find_object(__DIR__"dilao");
        if(!ob)
                ob = load_object(__DIR__"dilao");
        if(!ob)
                return notify_fail("��ɽ��������������ִ���������ʦ���档\n");

        if(!objectp(enter = ob->init_dilao(me)))
                return notify_fail("��ɽ��������������ִ���������ʦ���档\n");

        message_vision("$N���µ�ʯ�塰��¡��һ��ͻȻ����\n",me);
        tell_room(this_object(),me->name()+"������ȥ��ʯ���ַ��˻�����\n",({me}));
        me->move(enter);
        me->set("quest/huashan_quest/entered",1);
                if ( objectp(xin=present("shouxin", me)) &&
                        xin->query("for_xiuxiu") )
                        destruct(xin);

        // 20����֮����������������������࣬�������������Ѷ�
        if (me->query("zfx_start_time"))
        {
                if ( time() - (int)me->query("zfx_start_time", 1) < 1200 )
                {
                        me->add("zfx_in_20min", 1);
                }
                else 
                {
                        me->set("zfx_start_time", time());
                        me->set("zfx_in_20min", 1);
                }
        }
        else
        {
                me->set("zfx_start_time", time());
                me->set("zfx_in_20min", 1);
        }

        return 1;
}

