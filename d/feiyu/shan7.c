// Room: /wiz/louth/a/shan7.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����վ��һ���������Ƶ�ɽ���ϣ������Ƕ��͵�ʯ�ڣ�����
��ȥ�������ơ�������һ��Сé���ݣ����ſ�һ��ʯͷ�������
���š������¡��������֡�
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"shan6",
  "west" : __DIR__"maowu",
]));

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shenmi" : 1,
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
