// Room: /d/hangzhou/shutaishop.c

inherit ROOM;

void create()
{
	set("short", "�߲�̯");
	set("long", @LONG
�㿴��·��֧��һ��ľ�峵�����Ѿ����ƾ��ˣ�ľͷ������
��ĥ�ĺ����͵ķ��⣬��������ɢɢ�İڷ���һЩ�߲ˣ����˵�
�ϸ�������̯���Աߡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"guotaie2",
]));

	set("objects",([
	__DIR__"npc/shucai_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
