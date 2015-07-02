//
// Copyright 2010-2015 Fabric Software Inc. All rights reserved.
//

#include "CanvasMainWindow.h"
#include <FabricCore.h>
#include <FabricUI/Style/FabricStyle.h>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setOrganizationName( "{{FABRIC_COMPANY_NAME_NO_INC}}" );
  app.setApplicationName( "Fabric Canvas Standalone" );
  app.setApplicationVersion( "{{FABRIC_VERSION_MAJ}}.{{FABRIC_VERSION_MIN}}.{{FABRIC_VERSION_REV}}{{FABRIC_VERSION_SUFFIX}}" );
  app.setStyle(new FabricUI::Style::FabricStyle());

  QSettings settings;
  try
  {
    MainWindow mainWin( &settings );
    mainWin.show();
    for ( int i = 1; i < argc; ++i )
      mainWin.loadGraph( argv[i] );
    return app.exec();
  }
  catch ( FabricCore::Exception e )
  {
    printf("Error loading Canvas Standalone: %s\n", e.getDesc_cstr());
    return 1;
  }
}