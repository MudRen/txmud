// /d/changan/sroad3 �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵ��ϴ�֣�����������ٵ���Զ������������
�Ƚ�Ƨ����������ص����ڴ�������ż��Ҳ�м���������Ѳ����
���ﾭ����������������������������졣
LONG
        );
       set("exits", ([
	"west" : __DIR__"sroad2",
	"east" : __DIR__"sroad4",
	"north" : __DIR__"business",
 ]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
