#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������������ʮ���㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "down"  : __DIR__"liuheb",
            "up"    : __DIR__"liuhed",
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}