// zhenkou.c ��� 

inherit ROOM;
void create()
{
        set("short", "�봨��");
        set("long", @LONG
������ǻƺӰ��ߵ��봨������ˣ����������˺ܶ࣬�й�
�����̡����ˣ�Ҳ����������������ʿ����ֱ��ʯ��·�⻬ƽ
̹�����������졣
LONG
        );
       set("exits", ([
                "north"             : __DIR__"tulu3",
                "south"             : __DIR__"shilu",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
