// Room: /wiz/find/huapu/huatan.c

inherit ROOM;

void create()
{
	set("short", "��̳");
	set("long", @LONG
������һ��СС�����㻨̳����̳�����ʪ�����������
�Ӿ������˷�Ū����ֵ��ǻ�̳������С��Ҳû�С�
LONG
	);

	set("exits",([
	"south" : __DIR__"hua_pu/exit",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
