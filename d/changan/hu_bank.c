// Room: /d/changan/hu_bank.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С�����ϣ�Ҳ������ɧ�;�������ʫ���Եĵط���ż
��Ҳ��һЩ��͢��Ա��װ�����������档��ˮ�峺���ף���˵��
��ɽ����Ȫˮͨ��������곯͢��������Ҳ����Ϊ�˺�������
�����������뿪����֮ǰ��Ҫ�������(fill)Щˮ���ž�˵����
����һ·ƽ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jinghu",
  "west" : __DIR__"sroad9",
]));

	set("outdoors","changan");
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
