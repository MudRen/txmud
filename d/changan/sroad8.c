
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ϴ�ֵ���棬Ҳ��ȫ�����ǵĶ��Ͻǣ�����ƫƧ��
�ط������Ǻ��ٹ�����ֻ��ż��������������Ѳ����·����
����ûʲô�£������ĵط���û�������Ϊ������ǻ���
�֣��򱱱������½��ˡ�
LONG
        );

	set("exits", ([
	"west" : __DIR__"sroad7",
	"north" : __DIR__"eroad1",
	"east" : __DIR__"selling_room",
]) );
	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/yao_fanzi" : 1,
]));

        setup();

	replace_program(ROOM);
}
