//forest_c.c ԭʼɭ�����ġ�
inherit ROOM;
int do_climb(string arg);
int have=0;
void create()
{
        set("short","ԭʼɭ��");
        set("long", @LONG
����ԭʼɭ���У�ֻ��������ľ������ա��վ���������ԭ
��ɫ���㿪ʼ��������Ŀ����ɫ��������Ҳ�ᷳ������������Ҳ
�����˰����������������������ǲ���ֻ���Լ�һ�����ڣ�����
ǧƪһ�ɵ���ľ�����Ȼ��������һ������ܲ�Ѱ����
LONG
        );
        set("exits", ([
        "east":__DIR__"forest5",
        "west":__DIR__"forest4",
        "south":__DIR__"forest6",
        "north":__DIR__"forest5",
]));
        set("item_desc",([
        "����":"����ϸ�۲죬��Ȼ�������ܵ�֦Ҷ���ƺ���Ұ�޵���������\n",
]));
        setup();
}
void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me;
        object ob;
        me=this_player();
        if (!arg||arg!="����")
        {
                tell_object("��Ҫ����������\n",me);return 0;
        }
        if (arg=="����")
        {
                if (!(int)me->query_temp("mark/ʥ��"))
                {
                        message("vision","��Ȼ��Χ����ľһ��ζ��������˼���ȫ����װ���Ի���\n",environment(me));
                        for(int i=0;i<2;i++)
                                {
                                        ob=new(__DIR__"npc/tree_guardian");
                                        ob->move(__FILE__);
                                        message("vision","�Ի��ͺ����������ʥ���������\n\n",environment(me));
                                        ob->set_leader(me);
                                        ob->kill_ob(me);
                                        me->fight_ob(ob);
                                        return 1;
                                }
                }
                else
                {
                        message_vision("$N��ס����������������ȥ��\n",me);
                        me->move(__DIR__"tree1");
                        message_vision("$N����������������\n",me);
                        return 1;
                }
        }
}
