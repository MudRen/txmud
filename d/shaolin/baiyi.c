// Room: /d/shaolin/baiyi.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�����������µİ��µ���й����Ű��¹�������ʥ��ֻ
������Ŀ���飬���ֳ־�ƿ�����ֻ������������ڽ�ë���ϵ���
�������ϣ�ׯ�����ɡ��������Ʋ�ͯ�Ӻ�С��Ů������������
볡������������ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad5",
]));
        set(SAFE_ENV, 1);

	set("objects", ([
	__DIR__"npc/huiming" : 1,
]));

	setup();
	replace_program(ROOM);
}
