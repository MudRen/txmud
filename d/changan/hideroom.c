// Room: /d/changan/hideroom.c

inherit ROOM;

void create()
{
	object obj = new(GOLD_OB);
	obj->set_amount(20);
	obj->move(this_object());

	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䣬�����ǽ����һ�Ⱥ�С�Ĵ�
����
LONG
	);
	set("no_clean_up", 0);
	set("hide_exits",([
	"southeast" : __DIR__"fruitroom",
]));

	setup();
	replace_program(ROOM);
}
