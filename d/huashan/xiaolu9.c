// Room: /d/huashan/xiaolu9.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ����խ��ɽ��С·�����Զ���ɽ�¡��򱱸��ӣ�ֻ��
�ƺ�����һ����˿����ն�����һ��������᫵���С���򱱶�
ȥ������ͨ��ɽ�ɵ������ء�
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"yudao",
  "eastup" : __DIR__"luoyanpo",
  "southdown" : __DIR__"xiaolu8",
]));

	set("outdoors", "huashan");
	set("objects", ([
	__DIR__"npc/bird":1,
]));

	setup();
	replace_program(ROOM);
}
