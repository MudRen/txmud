// shilu3.c ʯ��· 

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
һ������ʯ��·���ֵ����Ե�С���������߹�������ʧʱ
��������˽������������ֵ����������봨�����ӣ������߾�
���봨��ĸ�����ջ�ˡ�
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu2",
                "south"             : __DIR__"shilu4",
                "east"              : __DIR__"fulai",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
