//forest9.c ��ظ�ԭͨ����ԭ��ԭʼɭ���Թ���
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
        "east":__DIR__"forest8",
        "west":__DIR__"forest8",
        "south":__DIR__"forestend",
        "north":__DIR__"forest9",
]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir=="south")
            me->delete_temp("forest/steps");
        if ( dir == "north"||dir == "east"||dir == "west"||dir == "saying")
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
