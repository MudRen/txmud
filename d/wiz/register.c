// Room: /d/wiz/register.c
// by Find.

#define BLOCK_CMDS ({"say","reply","look","register","who","hp","score","quit","suicide","inventory"})

inherit ROOM;

void create()
{
	set("short", "新玩家注册处");
	set("long", @LONG
为保障每一位玩家的权益，本游戏实行新玩家电子邮件注册
制度，这里就是新玩家进行注册的地方，在这里请您使用命令
register加上你的电子邮件地址进行注册。

例如：比如你真实的电子邮件地址为 player@me.com
      你输入："register player@me.com" 即可正确注册。

您的新密码将会发往这个地址，下次登陆必须使用我们发给您的
新密码进行。如果您现在还没有电子邮件地址，可以现在退出
(quit)去 http://freemail.sohu.com 申请有效的电子邮件地址，
这个账号我们会为您保留48 小时，过后如还未继续注册，此临
时账号会被删除。

进门处里这一块大木牌（pai）。

LONG
	);

	set("item_desc",([
	"pai" :"
首先请仔细检查注册命令里输入的电子邮件地址是否正确！！

这个游戏的注册过程是由机器自动完成的，在你还没有离开
游戏的时候注册信就已经发出了。如果注册信未能正确发出
会提示你从新输入注册命令，只有正确发出以后才会将注册
玩家断线。
你收到的时间是有你的邮件服务提供者决定的，如果他们转
信的时间快，正常情况下你应当在10秒钟之内收到。也就是
你关上zmud窗口打开邮件程序，就应当能收到了。最迟1-2个
小时也应当收到，
我们的游戏给玩家留了 48 个小时的收信时间应当是很充分
的。如果在这段时间内还未能收到您的新密码，建议你换一
个转信快的邮件服务提供者再次申请，或者向你的邮件服务
提供者进行咨询。

感谢你对这个游戏的关注。
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
		return notify_fail("您的电子邮件地址是什么？\n");

	if(sscanf(arg,"%*s@%*s.%*s") != 3)
		return notify_fail("电子邮件地址要符合 \"n@d.d\" 格式。\n");

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
