// /d/changan/whroad4  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ����ǵ�����·�����϶ˣ�����ȥ���ϻ�·������
�����Ͻ����ǻ��ڸ����Ľ������ܶ࣬���ߺ�ǽ���ߣ�ȴ������
��������һ��������
LONG
        );

       set("exits", ([
                "north"            : __DIR__"whroad3",
                "east"             : __DIR__"shroad1",
 ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
