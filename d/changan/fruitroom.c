// Room: /d/changan/npc/fruitroom.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
�߽���������۶����ˣ�һ���ŵĻ�������������������
��ɫ�ĸ���ˮ�����д���Բ��Ĵ����ϡ����Ʊ����Ĵ�Ѽ�桢��
�����ε�ƻ�����㽶�����ܡ����ӡ����ӡ����������в�����
�ӵ�ˮ�����ۣ���Ŀ�ˮ�Ѿ��ε��·����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wroad5",
]));

	if(random(20) < 4)
	set("hide_exits",([
	"northwest" : __DIR__"hideroom",
	]));

	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
