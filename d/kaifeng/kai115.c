// Room: /u/w/wangs/b/kai115.c

inherit ROOM;

void create()
{
	set("short", "�Լ�լ");
	set("long", @LONG
�ԼҴ�Ժ��һ�����ɻ��Ƶİ�����ݣ�ǰ��������Ǻ�ש��
�ɵ����ݣ�ʯ���ϵ���̦�ѱ�ϴˢ�øɸɾ������ɴ���ͨ��ǰԺ
������С��Ҳ������һ��ϸɳ������Ұ��ȫ����ƽ������·����
֦Ҳ�����޵��������룬һ����֪���������˺ܴ�Ĺ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai113",
  "east" : __DIR__"kai114",
]));
        set("objects",([
        __DIR__"npc/yongren":1,
]));

	setup();
	replace_program(ROOM);
}
