// shilu2.c ʯ��· 

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
һ������ʯ��·���ֵ����Ե�С���������߹�������ʧʱ
��������˽������������ֵ����������봨�����ӣ�����ǰ��
�����봨��Ŀ�ջ�ˣ��ڹ��ƺ�֮ǰ�ܶ������������ޡ�
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu",
                "south"             : __DIR__"shilu3",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
