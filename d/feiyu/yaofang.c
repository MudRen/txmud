// Room: /d/feiyu/yaofang.c

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��谵�ķ��䣬ӭ����һ������̨��̨���ϼ���һ��
ɳ����ǽ�߶���һ����𣬷����������Ÿ��ֲ�ҩ������������
����һ����ҩ����
LONG
	);

	set("exits",([
	"east" : __DIR__"yu19",
]));

	set("objects",([
	__DIR__"npc/ph_girl" : 1,
]));

	setup();
	replace_program(ROOM);
}
