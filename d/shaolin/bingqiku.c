// Room: /d/shaolin/bingqiku.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µı����⣬�������Ѵȱ�Ϊ����һЩ��������
���ڿ���ġ����ֵ�ɮ�����ù���ż����ʹ�����Ȼ������ȣ�
����������ı���ȴ�Ǻܶ࣬�䵶������һӦ��ȫ��ֻҪ������
�������ʱ���ſ���ʹ������ı����������������Ƕ���Ժ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"e_court",
]));

	set("objects", ([
	WEAPON_DIR"stick" : 2,
	__DIR__"npc/obj/jiedao" : 2,
	WEAPON_DIR"sword" : 1,
]));

	setup();
	replace_program(ROOM);
}
