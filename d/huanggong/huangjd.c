// Room: /d/huanggong/huangjd.c

inherit ROOM;

void create()
{
        set("short", "�ʼ���");
        set("long", @LONG
������ǻʼ���ǻ����Ƕ���ѧϰ�ĵط������ÿ�»�
�϶�Ҫ�����ﶽ�ٻ����Ǻúö��飬�Ա㽫���ܸ��õ��������
���������򱱾͵������ٹ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"zhaig",
  "south" : __DIR__"jiulb",
  "north" : __DIR__"ningsg",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}