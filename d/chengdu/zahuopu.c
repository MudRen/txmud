// Room: /wiz/louth/c/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��������ӻ��̣���������ȴ���Ÿ���������Ʒ��
һӦ��ȫ���ӻ��̵��ϰ���������΢Ц���������񲻴�������
���Ͼ��ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu5",
]));
        set("objects",([
        __DIR__"npc/zhaoboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
