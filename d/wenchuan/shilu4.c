// shilu4.c ʯ��· 

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
С���ʯ��·�Ϳ������ˣ�����ǰ���Կ���һƬ���֣��ݵ�
����˵���������־Ϳ��Ե���ƺӶɿڣ�·��������һ��С��ʯ
�С�
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu3",
                "south"             : __DIR__"shulin",
                //"west"              : __DIR__"baoshi",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
