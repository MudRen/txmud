// /d/yuehou/hroad1.c

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ����Ţ�Ļ���·�����ڸո��¹��꣬���Կ�������
�ǳ�ʪ��·�ϵ����˴Ҵ�ææ�ĸ�·���ƺ�û����ע�⵽�㡣
LONG
        );
       set("exits", ([
//                "north"             : __DIR__"hroad2"      // ����ӿ�
                "south"             : __DIR__"hroad2"
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}


