// Room: /d/wiz/wizroom.c

inherit ROOM;

void create()
{
	set("short", "��ʦ������");
	set("long", @LONG
�˵�����ʦ����԰�أ���ʦ��ʲô���⡢��������������
�˵����ԡ�
LONG
	);

	set("exits",([
	"down" : "/d/changan/jiulou",
]));

	setup();
	set("valid_startroom", 1);
	load_board("board_wiz");
}
