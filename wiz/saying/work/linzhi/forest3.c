//forest3.c ��ظ�ԭͨ����ԭ��ԭʼɭ���Թ���
inherit ROOM;
void create()
{
        set("short","ԭʼɭ��");
        set("long", @LONG
����ԭʼɭ���У�ֻ��������ľ������ա��վ���������ԭ
��ɫ���㿪ʼ��������Ŀ����ɫ��������Ҳ�ᷳ������������Ҳ
�����˰����������������������ǲ���ֻ���Լ�һ�����ڣ�����
ǧƪһ�ɵ���ľ����ֻ��Ͽ��߳�ȥ��
LONG
        );
        set("exits", ([
        "east":__DIR__"forest3",
        "west":__DIR__"forest2",
        "south":__DIR__"forest4",
        "north":__DIR__"forest3",
]));
        setup();
}
int valid_leave(object me, string dir)
{
        if ( dir == "north"||dir == "south"||dir == "east"||dir == "west"||dir == "saying")
            me->add_temp("forest/steps",1);
        if (me->query_temp("forest/steps") >70)
         {
                me->delete_temp("forest/steps");
                if (random(10)>7||(int)me->query_temp("mark/ʥ��"))
                me->move(__DIR__"forest_c");
                return notify_fail("\n");
         }  
        return ::valid_leave(me,dir);
}
