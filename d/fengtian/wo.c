// Room: /d/fengtian/wo.c

inherit ROOM;

void create()
{
	set("short", "�Է�");
	set("long", @LONG
������Ϣ�ĵط���Ҳ�ǽ���Ԫ�����Ԭ�ϵ��Է���Ԭ�ϼ޸�
�������꣬����Ҳ�ྴ���������Ԭ��һֱû�����ã����Խ���
������Ȣ�˶���̫��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf5",
  "west" : __DIR__ "er",
]));

	setup();
	replace_program(ROOM);
}
