// /d/changan/eroad4  �������

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
������ǳ����ǵĶ���������������Ķ��ţ���ר�����͹�
���ʹ�����·�����˶��ű����˺ӣ��������˵ķ�����Ի���
Ҳ��ÿ������ﾭ���ģ�����ţ�ƽʱ���ĺ��٣�ֻ�������˽�
ʱ���Ż�򿪣�����һ��������¡¡���ĳ���������֪��������
�����ˡ����������ǳ����Ķ��ţ��򱱺����������½֣�����
ֱͨ�ʹ��Ķ��š�
LONG
        );

	set("exits", ([
                "north"           : __DIR__"eroad5",
                "west"            : __DIR__"eroad9",
                "east"            : __DIR__"edoor",
                "south"           : __DIR__"eroad3", ]) );
	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
