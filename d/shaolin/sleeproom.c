// Room: /d/shaolin/sleeproom.c

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����������µ���Ϣ�ң�ǽ�Ϲ���һ���ܴ�����ӡ�������
һ���ſ��Ĵ�ͨ�̣�����ı��졣�Ӵ�������Կ��������һЩ
���£��ŵ���¯��Ʈ���ĵ����������㲻����Щ���ˡ�
LONG
	);
	set(SAFE_ENV,1);
        set("sleep_room", 1);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"e_court",
]));

	setup();
	replace_program(ROOM);
}
