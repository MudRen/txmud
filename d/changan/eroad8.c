// /d/changan/eroad8  ���½�

inherit ROOM;

void create()
{
        set("short", "���½�");
        set("long", @LONG
�����ǳ����ǵ�����ǣ�����˵�����Ǻڵ����������
�ط���һ���Ҳ��Ϊ������С����Ϣ����Ӷɱ�ֵ����ǲ�Լ��ͬ��
�ۼ����������������˵�Ű�����ŵ��ϵ����ƣ�����㲻
���������е�һԱ������������������֪���ơ�����������
�ǳ����ǵĶ���֣������������������ڳ����ǵı�����ˡ�
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad1",
                "south"           : __DIR__"eroad7",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
