// Room: /u/w/wangs/b/kai114.c

inherit ROOM;

void create()
{
	set("short", "�ԼҴ�Ժ");
	set("long", @LONG
�ԼҴ�Ժ��һ�����ɻ��Ƶİ�����ݣ�ǰ��������Ǻ�ש��
�ɵ����ݣ�ʯ���ϵ���̦�ѱ�ϴˢ�øɸɾ������ɴ���ͨ��ǰԺ
������С��Ҳ������һ��ϸɳ������Ұ��ȫ����ƽ������·����
֦Ҳ�����޵��������룬һ����֪���������˺ܴ�Ĺ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai115",
]));
        set("objects",([
        __DIR__"npc/zhao":1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
