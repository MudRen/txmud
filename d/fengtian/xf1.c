// Room: /d/fengtian/xf1.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
�ɻ����ͨ���򱱾͵�������᷿���᷿�ǽ���С�ĵط�
����ʰ�ķǳ����£�����Ҳ�㽫�����鷿�ˣ�����ʱ���������
��һЩ��Ҫ�Ŀ��ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf3",
]));

	setup();
	replace_program(ROOM);
}
