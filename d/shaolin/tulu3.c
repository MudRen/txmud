// Room: /d/shaolin/tulu3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���ӿ����ݵ���·������������ţ������õ�ʱ��������
��Ļ�����������ʱ��������Ţ�����������Ĵ���û��Ǯ����·��
ֻ�ôպ���������
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"tulu2",
        "east" : __DIR__"k_s24",
]));

	setup();
	replace_program(ROOM);
}
