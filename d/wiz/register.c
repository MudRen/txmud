// Room: /d/wiz/register.c
// by Find.

#define BLOCK_CMDS ({"say","reply","look","register","who","hp","score","quit","suicide","inventory"})

inherit ROOM;

void create()
{
	set("short", "�����ע�ᴦ");
	set("long", @LONG
Ϊ����ÿһλ��ҵ�Ȩ�棬����Ϸʵ������ҵ����ʼ�ע��
�ƶȣ������������ҽ���ע��ĵط�������������ʹ������
register������ĵ����ʼ���ַ����ע�ᡣ

���磺��������ʵ�ĵ����ʼ���ַΪ player@me.com
      �����룺"register player@me.com" ������ȷע�ᡣ

���������뽫�ᷢ�������ַ���´ε�½����ʹ�����Ƿ�������
��������С���������ڻ�û�е����ʼ���ַ�����������˳�
(quit)ȥ http://freemail.sohu.com ������Ч�ĵ����ʼ���ַ��
����˺����ǻ�Ϊ������48 Сʱ�������绹δ����ע�ᣬ����
ʱ�˺Żᱻɾ����

���Ŵ�����һ���ľ�ƣ�pai����

LONG
	);

	set("item_desc",([
	"pai" :"
��������ϸ���ע������������ĵ����ʼ���ַ�Ƿ���ȷ����

�����Ϸ��ע��������ɻ����Զ���ɵģ����㻹û���뿪
��Ϸ��ʱ��ע���ž��Ѿ������ˡ����ע����δ����ȷ����
����ʾ���������ע�����ֻ����ȷ�����Ժ�ŻὫע��
��Ҷ��ߡ�
���յ���ʱ����������ʼ������ṩ�߾����ģ��������ת
�ŵ�ʱ��죬�����������Ӧ����10����֮���յ���Ҳ����
�����zmud���ڴ��ʼ����򣬾�Ӧ�����յ��ˡ����1-2��
СʱҲӦ���յ���
���ǵ���Ϸ��������� 48 ��Сʱ������ʱ��Ӧ���Ǻܳ��
�ġ���������ʱ���ڻ�δ���յ����������룬�����㻻һ
��ת�ſ���ʼ������ṩ���ٴ����룬����������ʼ�����
�ṩ�߽�����ѯ��

��л��������Ϸ�Ĺ�ע��
"
]));

	set("register_room",1);

	setup();
}

void init()
{
	if(!wizardp(this_player()))
	{
		add_action("do_quit","quit");
		add_action("do_reg","register");
		add_action("block_cmds","",1);
	}
}

int do_reg(string arg)
{
	if(!arg)
		return notify_fail("���ĵ����ʼ���ַ��ʲô��\n");

	if(sscanf(arg,"%*s@%*s.%*s") != 3)
		return notify_fail("�����ʼ���ַҪ���� \"n@d.d\" ��ʽ��\n");

	SMTP_D->send_mail(this_player(),arg);
	return 1;
}

int do_quit(string arg)
{
	object me = this_player();

	if(!wizardp(me) && me->query("new_begin"))
		SMTP_D->add_user(me->query("id"));
	return 0;
}

int block_cmds()
{
        if(wizardp(this_player()))
                return 0;
        else if( member_array(query_verb(),BLOCK_CMDS) == -1 )
                return 1;
        else return 0;
}
