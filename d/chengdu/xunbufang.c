// Room: /wiz/louth/c/xunbufang.c

inherit ROOM;

void create()
{
	set("short", "Ѳ����");
	set("long", @LONG
����һ����ķ��䣬���ɫ��ǽ���Ϲ��ż���������Ƥ��
֮�����Ʒ���������һ�Ŵ�ľ�����Աߵĳ���ľ���������ż�
λ�����µ�Ѳ����̸Ц�Ȳ衣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fuenlu",
]));
        set("objects",([
        NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
